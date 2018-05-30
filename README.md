# Quantum

Named after the concept of "quantum teleportation", Quantum provides both peer discovery and reliable communication with and between Particles.

## Basic usage

For basic usage, see `examples/basic-usage`. In short, Quantum exposes one class, `Quantum`, modeled after the built-in networking APIs. The most important implementation detail is the "perform" function, which should have the following signature:

```
void perform(uint8_t command) {
  // ...
}
```

Each byte received over the network will be sent to this function. See Limitations, below, for more information.

- `new Quantum(perform)` — Creates a new `Quantum` instance with the provided `perform` function (which can have _any_ name, but signature described above).
- `begin` — Modeled after the built-in networking APIs, a `Quantum` instance is silent until `begin` is called. This starts the internal timers that broadcast beacons and receive bytes over the network.

## Technical details

- **Discoverability** — Quantum uses UDP multicast to broadcast device state to other listening peers. At the moment, the only state broadcast is the device's ID.
- **Communication** — Quantum uses TCP for communication. Each Quantum instance gets its own TCP server, and each byte received over this server is sent to the configured perform function.

## Limitations

At the time, Quantum is limited in the following ways:

- Because the built-in TCP server only allows a single connected client at a time, this limitation carries over to Quantum. Other clients are queued, and will be served once the primary client disconnects. _As a result, clients should send the desired commands and disconnect ASAP._
- To simplify the API, perform functions only accept a single byte at a time. This should allow for building a more robust protocol over Quantum.

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add Quantum_myname` to add the library to a project on your machine or add the Quantum_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library.

If you wish to make your library public, use `particle library publish` or `Publish` command.

## License

```
Copyright 2018 Michael Schoonmaker

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
